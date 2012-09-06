module Main where

f :: Int->Int->[[Integer]]->(Integer,Integer,[Char])
f n m s 
    | n == 0 && m == 0 = p (s!!n!!m) []
    | m == 0 = add (f (n-1) 0 s) (p (s!!n!!m) ['D']) 
    | n == 0 = add (f 0 (m-1) s) (p (s!!n!!m) ['R'])
    | otherwise = min' (add (f n (m-1) s) (p (s!!n!!m) ['R'])) (add (f (n-1) m s) (p (s!!n!!m) ['D'])) 

p :: Integer ->[Char] -> (Integer , Integer,[Char])
p a d = (k a , t a,d)
    where 
        k 0 = 0
        k a = if a `mod` 2 == 0 then 1 + (k $ div a 2) else 0
        t 0 = 0
        t a = if a `mod` 5 == 0 then 1 + (t $ div a 5) else 0

min' (a,b,c) (a',b',c') 
    | (min a b) < (min a' b') = (a,b,c)
    | (min a b) == (min a' b') && (max a b) <= (max a' b') = (a,b,c)
    | otherwise = (a',b',c')

add (a,b,c) (a',b',c') = (a+a',b+b',c++c')

val (a,b,_) = min a b

main = do 
    a <- getLine
    b <- getContents
    let ln = map (map read) (map words $ lines b )
    let (m,n,o) = f ((read a)-1) ((read a)-1) ln 
    print $ min m n
    putStrLn o
