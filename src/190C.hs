module Main where


f (x:xs) n 
    | x == "pair" = "pair<" ++ (f xs (n+1)) ++ ">"
    | x == "int"  = "int," ++  (f xs (n-1))
f [] n = ""
