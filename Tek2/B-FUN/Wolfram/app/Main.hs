module Main where
import System.Exit
import Text.Read
import System.Environment
import System.Exit (exitWith)
import Data.Bits
import Lib

firstLine:: Int -> Int -> String
firstLine first second = replicate first ' ' ++ "*" ++ replicate (second - 1) ' '

getRightChar:: Int -> Int -> String
getRightChar rule bit
    | ((rule `shiftR` bit) .&. 1) == 1 = "*"
    | otherwise = " "

composition:: String -> Int
composition (' ':' ':' ':_) = 0
composition (' ':' ':'*':_) = 1
composition (' ':'*':' ':_) = 2
composition (' ':'*':'*':_) = 3
composition ('*':' ':' ':_) = 4
composition ('*':' ':'*':_) = 5
composition ('*':'*':' ':_) = 6
composition ('*':'*':'*':_) = 7
composition _ = 999

createMyLine:: Int -> String -> String
createMyLine _ [] = []
createMyLine _ [_] = []
createMyLine rule [' ', ' '] = getRightChar rule 0
createMyLine rule [' ', '*'] = getRightChar rule 1
createMyLine rule ['*', ' '] = getRightChar rule 2
createMyLine rule ['*', '*'] = getRightChar rule 3
createMyLine rule str = getRightChar rule (composition str) ++ createMyLine rule (tail str)

genLine:: Int -> Int -> String -> String
genLine 0 _ prev = prev
genLine myLine rule prev = genLine (myLine -1) rule ("  " ++ createMyLine rule prev ++ " ")

myDisplayLine :: Int -> Int -> Int -> Int -> String -> IO ()
myDisplayLine _ _ 0 _ _ = exitSuccess
myDisplayLine rule start line window prev = putStrLn (take window (drop start prev)) >> myDisplayLine rule (start + 1) (line - 1) window ("  " ++ createMyLine rule prev ++ " ")
-- Décomposer avec des wheres pour que ça soit plus lisible / fonction trop longue;
-- Nom de fonction

myWolfram:: Maybe Conf -> IO ()
myWolfram Nothing = putStrLn "Arguments Issue Found ihiih !" >> exitWith(ExitFailure 84)
myWolfram (Just(Conf (Just r) (Just s) (Just l) (Just w) (Just m))) = myDisplayLine r s l w (genLine s r (firstLine((w `div` 2) + m) ((w `div` 2) - m)))
myWolfram _ = putStrLn "Arguments Issue Found ihiih !" >> exitWith(ExitFailure 84)

main :: IO ()
main = do
    args <- getArgs
    let conf = parseArgs args createDefaultConfig
    myWolfram (conf)
-- Check du conf dans le main comme ça j'ai pas de Maybe Conf dans le MyWolfram