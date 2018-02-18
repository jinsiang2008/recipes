import argparse
import sys
from urllib.request import urlopen # py3, of course
from multiprocessing.dummy import Pool as ThreadPool 


def run(url, requests, concurrency):
    # Make the Pool of worker threads
    pool = ThreadPool(concurrency)
    results = pool.map(urlopen, [url]*requests) 
    pool.close()
    pool.join()
    return [getattr(resp, "status") for resp in results]

def main():
    parser = argparse.ArgumentParser(
        description = "Throw a load of HTTP requests"
    )
    parser.add_argument("-n", "--number",
                        help=("Total number of requests to send"),
                        type=int,
                        default=1)
    parser.add_argument("-c", "--concurrency",
                        help=("Concurrent requests"),
                        type=int,
                        default=1)  
    parser.add_argument('url', help='URL to hit', nargs='?') # at least 1

    args = parser.parse_args()

    if args.url is None:
        print ("Give me a URL")
        sys.exit(0)
    res = run(args.url, args.number, args.concurrency)
    print (res)

if __name__ == '__main__':
    main()