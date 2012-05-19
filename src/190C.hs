module Main where

f :: [Int] -> [[Char]] -> [[Char]] -> [Char]
f (2:2:1:xs) (a:b:c:ys) d = f (2:xs) ((c++"<"++b++","++a++">"):ys) d
f (2:1:xs) ys ("int":d) = f (2:2:1:xs) ("int":ys) d
f (2:1:xs) ys ("pair":d) = f (1:2:1:xs) ("pair":ys) d
f (1:xs) ys ("int":d) = f (2:1:xs) ("int":ys) d
f (1:xs) ys ("pair":d) = f (1:1:xs) ("pair":ys) d
f (2:[]) [y] [] = y
f [] [] ("int":d) = f (2:[]) ("int":[]) d
f [] [] ("pair":d) = f (1:[]) ("pair":[]) d
f [] [] [] = ""
f _ _ _ = "Error occurred"

main = do
    a <- getLine
    b <- getLine
    putStrLn $ f [] [] (words b)
