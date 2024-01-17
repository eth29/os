#DETECT NUMBER,VOWEL AND CONSONANT FROM A STRING
read -p "Enter a string: " str
num=0
vow=0
con=0
for (( i=0; i<${#str}; i++ ))
do
    ch=${str:$i:1}
    if [[ $ch =~ [0-9] ]]
    then
        num=$(( $num + 1 ))
    elif [[ $ch =~ [aeiouAEIOU] ]]
    then
        vow=$(( $vow + 1 ))
    elif [[ $ch =~ [a-zA-Z] ]]
    then
        con=$(( $con + 1 ))
    fi
done
echo "Number of digits: $num"
echo "Number of vowels: $vow"
echo "Number of consonants: $con"
