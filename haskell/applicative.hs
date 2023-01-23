import Control.Applicative

sequenceA :: (Applicative f) => [f a] -> f [a]
sequenceA [] = pure []
sequenceA (x:xs) = (:) <$> x <*> sequenceA xs

sequenceA' :: (Applicative f) => [f a] -> f [a]
sequenceA' = foldr (\x acc -> (:) <$> x <*> acc) (pure [])

sequenceA'' :: (Applicative f) => [f a] -> f [a]
sequenceA'' = foldr (liftA2 (:)) (pure [])
