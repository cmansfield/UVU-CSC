**Listparse**

listparse was created by Chris Mansfield
This program Iterates through a list of words and concatenates them together as long as their total char length equals the targetSize specified.

*Example:*

test.txt contains:
```
test
home
howdy
joy
```

./listparse 9 test.txt

will generate:
```
testhowdy
homehowdy
howdytest
howdyhome
```

Useful if you have a collection of info
and you want to concatenate them together
to a specific password length
