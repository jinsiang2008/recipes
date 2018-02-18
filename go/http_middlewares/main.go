package main

import (
	"net/http"
)

// go run *.go
func main() {
	mux := http.NewServeMux()
	mux.HandleFunc("/limit", okHandler)

	// Wrap the servemux with the limit middleware.
	http.ListenAndServe(":4000", logging(limit(mux)))
}

func okHandler(w http.ResponseWriter, r *http.Request) {
	w.Write([]byte("OK"))
}

// TODO: Testing, see justforfunc #16: unit testing HTTP servers
// https://www.youtube.com/watch?v=hVFEV-ieeew
