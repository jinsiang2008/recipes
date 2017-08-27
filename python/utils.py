# Flatten embedded list
from compiler.ast import flatten
flatten([1, [2], [3, [[4]]])

# Get docstring from a function
def my_func():
    "Docstring blabla"
    pass
my_func.__doc__

# Get function signature
# https://docs.python.org/3.4/library/inspect.html#inspect.signature

# Call function by it's literal name
# https://stackoverflow.com/questions/3061/calling-a-function-of-a-module-from-a-string-with-the-functions-name-in-python

# Get list of methods in a class
# https://stackoverflow.com/questions/1911281/how-do-i-get-list-of-methods-in-a-python-class
# inspect.getmembers()

# Get CPU numbers
from multiprocessing import cpu_count
print (cpu_count())
