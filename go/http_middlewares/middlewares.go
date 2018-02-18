// Credit to http://www.alexedwards.net/blog/how-to-rate-limit-http-requests
// And https://www.nicolasmerouze.com/middlewares-golang-best-practices-examples/
package main

import (
	"log"
	"net/http"
	"time"

	"golang.org/x/time/rate"
)

const (
	r = 2 // permit consum r tokens per second
	b = 5 // token bucket size b
)

var limiter = rate.NewLimiter(r, b)

func limit(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		if limiter.Allow() == false {
			http.Error(w, http.StatusText(429), http.StatusTooManyRequests)
			return
		}

		next.ServeHTTP(w, r)
	})
}

func logging(next http.Handler) http.Handler {
	// To logging response, it need to wrap HandlerFunction
	// See https://github.com/urfave/negroni/blob/master/logger.go
	fn := func(w http.ResponseWriter, r *http.Request) {
		next.ServeHTTP(w, r)
		log.Printf("%s %s %s %s",
			time.Now().Format(time.RFC3339),
			r.Host,
			r.Method,
			r.URL.Path)
	}
	return http.HandlerFunc(fn)
}
