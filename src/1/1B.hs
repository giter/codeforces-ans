module Main where

import Data.Char


t = '~':['A'..'Z']

f n 
    | n < 27 = [t!!n] 
    | otherwise = (f $ n `div` 26) ++ [(t !! ((n `mod` 26) + 1))]

f' [] = 0
f' p  = (ord $ last p ) - (ord 'A') + 1 + 26 * (f' $ init p)



