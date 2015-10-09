import sys
import random

x = "y"
while x == "y":
  num = random.randint(1,6)
  print num
  x= raw_input('want to continue? (y/n) ')
print "Goodbye !"