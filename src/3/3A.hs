module Main where

import Data.Char

f (x,y) (x',y')
    |  x == x' && y < y' = 'U':'\n':(f (x,y+1) (x',y'))
    |  x == x' && y > y' = 'D':'\n':(f (x,y-1) (x',y'))
    |  x <  x' && y == y'= 'R':'\n':(f (x+1,y) (x',y'))
    |  x >  x' && y == y'= 'L':'\n':(f (x-1,y) (x',y'))
    |  x <  x' && y < y' = 'R':'U':'\n':(f (x+1,y+1) (x',y'))
    |  x <  x' && y > y' = 'R':'D':'\n':(f (x+1,y-1) (x',y'))
    |  x >  x' && y < y' = 'L':'U':'\n':(f (x-1,y+1) (x',y'))
    |  x >  x' && y > y' = 'L':'D':'\n':(f (x-1,y-1) (x',y'))
    |  x == x' && y == y' = []

p (x:y:[]) = ((ord x) - (ord 'a')+1,(ord y) - (ord '0'))

main = do
    a <- getLine
    b <- getLine
    let k =  f (p a) (p b) in
        do
            print $ length (filter (=='\n') k ) 
            putStr k
            return ()
    
