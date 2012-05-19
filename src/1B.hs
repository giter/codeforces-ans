module Main where

import Data.Char


t = '~':['A'..'Z']

f n 
    | n < 27 = [t!!n] 
    | otherwise = (f $ n `div` 26) ++ [(t !! ((n `mod` 26) + 1))]

f' [] = 0
f' p  = (ord $ last p ) - (ord 'A') + 1 + 26 * (f' $ init p)

idx c [] = -1
idx c (x:xs) = 
    idx' c (x:xs) 0
    where
        idx' c (x:xs) n = if x == c then n else idx' c xs (n+1)
        idx' c [] n = -1
 
check str = if (idx 'R' str == 0) && (idx 'R' str) > ((idx 'C' str)+1) then (splitAt $ idx 'C' str )  else 

    
