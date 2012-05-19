module Main where

f [n,m,a] = (div (n+a-1) a) * (div (m+a-1) a)


main = do
    a <- getLine
    print $ f $ map read $ words a
    
