import redis
ss =   """{
    "Test": "pub"
}"""

if __name__ == "__main__":
    r = redis.Redis()
    r.publish("test", ss)
