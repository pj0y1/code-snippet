import Control.Monad
main = do
	seasons <- forM [1,2,3,4] (\a -> do  
		putStrLn ("which season it is according to " ++ (show a) ++ " ?")
		season <- getLine
		return (season ++ show a) )
	mapM_ putStrLn seasons
