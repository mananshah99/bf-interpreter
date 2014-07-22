bf-interpreter
==============

Interpreter for the instruction-pointer based esoteric language

Run: gcc main.c -o exec && exec "filename.bf"

Cmd  Effect                               
---  ------                               
+    Increases element under pointer      
-    Decrases element under pointer       
>    Increases pointer                    
<    Decreases pointer                    
[    Starts loop, flag under pointer      
]    Indicates end of loop                
.    Outputs ASCII code under pointer     
,    Reads char and stores ASCII under ptr
