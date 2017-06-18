# c-sig
One of my first "just for fun" C projects (circa 1999)

Back in the late '90s, it was the height of geekdom to have a compact, obfuscated source code email signature that executed to do something interesting, like so:
```c
char*z="lLMZZNLZLUGNLLZZP@QTRAYLMYASRYJbIl";main(x,y){for(x=
0;(y=z[x/2]-60)>-60/*  James Bernsen  */;x++){y=x%2?y%7:y/7;
y=y<2||y==5?y+40:y>1&&y<4?15*y+2:y==4?y+91:y+4;putchar(y);}}
```

Which, in this case, compiles as C into an executable that writes my name as ASCII art:
```
   /_ _  _  _   /_)_ _    _ _  
(_/(///)(-_)   /_)(-/ /)_) (-/)

```
