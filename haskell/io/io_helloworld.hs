import Data.Char
main = do 
	putStrLn "hello, world"
	putStrLn "What's your name?"
	name <- getLine
	putStrLn "What's your gender?"	
	gender <- getLine
	let uppername = map toTitle name ;
		sex = read gender :: Gender
	putStrLn (uppername ++ ", your gender is " ++ show sex)

data Gender = Male | Female deriving (Eq, Show, Read)
