#! /bin/bash

read -p "Enter week and problem number (eg. second week's problem B Input: 2 2):" WEEK NUMBER
cd "week_$WEEK/problem_$NUMBER"
clang++ -o exec *.cpp -std=c++17
RESULT=$(./exec < *.in)
OUTPUT=$(cat *out)
RSLT_LN=$(echo "$RESULT" | wc -l | xargs)
RSLT_WC=$(echo "$RESULT" | wc -w | xargs)
OTPT_LN=$(echo "$OUTPUT" | wc -l | xargs)
OTPT_WC=$(echo "$OUTPUT" | wc -w | xargs)

# echo "RSLT_LN=$RSLT_LN RSLT_WC=$RSLT_WC OTPT_LN=$OTPT_LN OTPT_WC=$OTPT_WC"

if [ $RSLT_WC -ne $OTPT_WC ] || [ $RSLT_LN -ne $OTPT_LN ]
then
	echo "Invalid output format"
	cd ~/2022-2/문제해결기법
	exit 1
fi

for LINE_NUM in $(seq 1 $OTPT_LN)
do	
	# echo $OTPT_LN
	RSLT=$(echo "$RESULT" | awk -v num=$LINE_NUM 'NR==num{print $0}')
	OTPT=$(echo "$OUTPUT" | awk -v num=$LINE_NUM 'NR==num{print $0}')
	n=$(echo "$OTPT" | wc -w | xargs)
	#echo "${LINE_NUM}: ${RSLT} ${OTPT}"
	for I in $(seq 1 $n)
	do
		WORD_1=$(echo "$RSLT" | awk -v C=$I '{print $C}' | tr -d '\015')
		WORD_2=$(echo "$OTPT" | awk -v C=$I '{print $C}' | tr -d '\015') 
		if [[ "$WORD_1" != "$WORD_2" ]]
		then
			echo "Wrong Answer"
			echo "WORD_1=$WORD_1"
			echo "WORD_2=$WORD_2"
			cd ~/2022-2/문제해결기법
			exit 1
		fi
	done
done

echo "correct"
