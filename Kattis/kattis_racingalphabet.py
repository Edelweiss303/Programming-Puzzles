 # Kattis problem: Racing Around The Alphabet
 #
 # Topic: Other
 #
 # Level: easy
 # 
 # Brief problem description: 
 #
 # Calculated the expected time for a player to run around a circle, with evenly spaced  
 # letters around the outside, given a word to spell
 #
 #Solution Summary:
 #
 #   Divide the circumference of the circle by 8 then run around the left if the next letter is more than 14 
 #   spaces away, or run around the right if the letter is 14 or less spaces away
 #
 # Used Resources:
 #
 #   ...
 #
 # I hereby certify that I have produced the following solution myself
 # using only the resources listed above in accordance with the CMPUT
 # 403 collaboration policy.
 #
 #
 # Rishi Barnwal
 #
 import math

N = input()
phrases = []
i = 0
points = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N",
          "O","P","Q","R","S","T","U","V","W","X","Y","Z"," ","'"]

diametre = math.pi*60
section = diametre/28
timeForSection = section/15
totalTime = 0


for i in range(N):
    words = raw_input()
    phrases.append(words)

for i in range(N):
    totalTime = 0
    currentPhrase = phrases[i]
    for letter in currentPhrase:
        if(totalTime == 0):
            currentIndex = points.index(letter)
            totalTime += 1
        else:
            nextIndex = points.index(letter)
            
            if(abs(nextIndex - currentIndex) > 13):
                totalTime +=(28 - abs(nextIndex - currentIndex)) * timeForSection
                totalTime += 1
            else:
                totalTime += abs(nextIndex - currentIndex) * timeForSection
                totalTime += 1
            
            currentIndex = nextIndex

    print totalTime
