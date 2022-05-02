module Lib (Conf (..), parseArgs, createDefaultConfig) where
import System.Exit
import Text.Read
import System.Environment
import System.Exit (exitWith)

data Conf = Conf {
    rule :: Maybe Int,
    start :: Maybe Int,
    line :: Maybe Int,
    window :: Maybe Int,
    move :: Maybe Int
}

createDefaultConfig:: Conf
createDefaultConfig = Conf {rule=Nothing, start=(Just 0), line=(Just (-1)), window=(Just 80), move=(Just 0)}

parseArgs:: [String] -> Conf -> Maybe Conf
parseArgs [] conf = errorHandling (Just conf)
parseArgs ("--rule":r:is) conf = parseArgs is conf {rule = readMaybe r}
parseArgs ("--start":s:is) conf = parseArgs is conf {start = readMaybe s}
parseArgs ("--lines":l:is) conf = parseArgs is conf {line = readMaybe l}
parseArgs ("--window":w:is) conf = parseArgs is conf {window = readMaybe w}
parseArgs ("--move":m:is) conf = parseArgs is conf {move = readMaybe m}
parseArgs _ _ = errorHandling Nothing

checkArgsVal:: Maybe Conf -> Maybe Conf
checkArgsVal Nothing = Nothing
checkArgsVal (Just(Conf r s l w m))
    | r `notElem` [Just 30, Just 90, Just 110] = Nothing
    | s < Just 0 = Nothing
    | w < Just 0 = Nothing
    | otherwise = (Just(Conf r s l w m))

errorHandling:: Maybe Conf -> Maybe Conf
errorHandling Nothing = Nothing
errorHandling (Just(Conf Nothing _ _ _ _)) = Nothing
errorHandling (Just(Conf r s l w m)) = checkArgsVal (Just(Conf r s l w m))

