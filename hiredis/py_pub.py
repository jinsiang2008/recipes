import redis
ss =   """{
   "ostd":{
      "ost1":{
         "type":"regular",
         "lsu":"lsu"
      },
      "ost2":{
         "type":"regular",
         "lsu":"lsu"
      },
      "ost3":{
         "type":"regular",
         "lsu":"lsu",
         "111":"111"
      },
      "serialnum":{
         "serialnum":"00505693C854"
      }
   }
}"""

if __name__ == "__main__":
    r = redis.Redis()
    r.publish("test", ss)
