

# números
print("int -> ", type(13))
print("float -> ", type(-3.12))
print("complex -> ", type( 2 + 3j))

# string
print("str -> ", type("ariku"))

# boolean - flags
print("boolean ->", type(True))
if(0 == False):
    print("boolean if 0 == false -> true ", type(True))
    
    
#collecions
print("list -> ", type([1, 2, 3]))
print("tuple ->", type((1, 2, 3)))

print("set ->", type({1, 2, 3}))
print("frozenset ->", type(frozenset([1, 2, 3])))
print("dict ->", type({"a": 1, "b": 2}))

print("range ->", type(range(5)))


# extras
print("NoneType ->", type(None))
print("bytes ->", type(b"abc"))
print("bytearray ->", type(bytearray(3)))
print("memoryview ->", type(memoryview(b"abc")))
def f():
    pass

print("function ->", type(f))
class Persona:
    pass

print("class ->", type(Persona))
import math
print("module ->", type(math))

print("slice ->", type(slice(1, 5)))
print("ellipsis ->", type(...))


