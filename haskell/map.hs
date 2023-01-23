import qualified Data.Map as Map

fromList' :: Ord k => [(k,v)] -> Map.Map k v
fromList' = foldr (\(k,v) acc -> Map.insert k v acc) Map.empty

phonebookToMap :: Ord k => [(k,String)] -> Map.Map k String
phonebookToMap = Map.fromListWith (\v1 v2 -> v1 ++ "," ++ v2)

phonebookToMap' :: Ord k => [(k,String)] -> Map.Map k [String]
phonebookToMap' = Map.fromListWith (++) $ map (\(k,v) -> (k,[v]))
