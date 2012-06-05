module Main where

-- Illegal
illegal m = 
    let nx = foldl (\x y -> if y == 'X' then x+1 else x) 0 $ concat m
        n0 = foldl (\x y -> if y == '0' then x+1 else x) 0 $ concat m
    in
        abs(nx-n0) >= 2 || n0 > nx
        || ((h m 'X') && (h m '0'))
        || ((h m 'X') && (v m '0'))
        || ((h m '0') && (v m 'X'))
        || ((v m 'X') && (v m '0'))
        || (n0<nx && ((h m '0')||(v m '0')||(c m '0')) )
        || (n0==nx && ((h m 'X')||(v m 'X')||(c m 'X')))

-- Winner
winner m = if (h m 'X') || (v m 'X') || (c m 'X') then "the first player won" else 
                if (h m '0') || (v m '0') || (c m '0') then "the second player won" else "no winner" 

-- Draw
draw m = 
    let nx = foldl (\x y -> if y == 'X' then x+1 else x) 0 $ concat m
        n0 = foldl (\x y -> if y == '0' then x+1 else x) 0 $ concat m
    in
        if nx+n0 == 9 then "draw" else "no draw"

-- First
f m =  
    let nx = foldl (\x y -> if y == 'X' then x+1 else x) 0 $ concat m
        n0 = foldl (\x y -> if y == '0' then x+1 else x) 0 $ concat m
    in
        if nx>n0 then "second" else "first"


-- Horizon 
h m x =
    h' m 0 x || h' m 1 x || h' m 2 x
    where
        h' m n x = (m!!0!!n) == x &&  (m!!1!!n) == x && (m!!2!!n) == x
-- Line
v m x =
    v' m 0 x || v' m 1 x || v' m 2 x
    where
        v' m n x = (m!!n!!0) == x &&  (m!!n!!1) == x && (m!!n!!2) == x
-- Cross
c m x =
    (m!!0!!0) == x && (m!!1!!1) == x && (m!!2!!2) == x
    || (m!!0!!2) == x && (m!!1!!1) == x && (m!!2!!0) == x
check m =
    if illegal m then "illegal" else 
        if winner m /= "no winner" then winner m else 
            if draw m == "draw" then draw m else
                f m

main = do
    a <- getLine
    b <- getLine
    c <- getLine
    putStrLn $ check [a,b,c]
