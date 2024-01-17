#CHECK A NUMBER IS AMSTRONG OR NOT
echo "Enter a number"
read num
rem=0
sum=0
temp=$num
while [ $num -gt 0 ]
do
rem=$((num % 10))
sum=$((sum + rem * rem * rem))
num=$((num / 10))
done
if [ $temp -eq $sum ]
then
echo "Number is armstrong"
else
echo "Number is NOT armstrong"
fi
