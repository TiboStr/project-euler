-- By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
-- What is the 10 001st prime number?

nthPrime n = [x | x <- [2 ..], isPrime x] !! (n -1)
  where
    isPrime n
      | n < 2 = False
      | n == 2 = True
      | otherwise = null ([x | x <- [2 .. ceiling (sqrt (fromIntegral n))], n `mod` x == 0])

main = do   putStr "The 10001st prime number is: "
            print (nthPrime 10001)
