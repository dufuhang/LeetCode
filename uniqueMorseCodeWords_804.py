class Solution:
    def uniqueMorseRepresentations(self, words):
        d = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        transformations = []
        for str in words:
            temp = []
            for i in str:
                temp.append(d[ord(i) - 97])
            transformations.append(''.join(temp))
        return len(set(transformations))
            
            