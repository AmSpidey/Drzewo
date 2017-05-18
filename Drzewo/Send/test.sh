if [ $1 = "-v" ] ; then
	PROGRAM=$2
	DIR=$3

else
	PROGRAM=$1
	DIR=$2
fi

for inFile in $DIR/*.in; do 
	./$PROGRAM -v <$inFile 2> "temp.err" | diff -q - "${inFile%.*}.out";
	if [[ $? != 0 ]]; then
        	echo "NIEPOPRAWNE WYJŚCIE STDOUT DLA WEJŚCIA $inFile"
    	fi

	if [ $1 = "-v" ] ; then
		diff -q "temp.err" "${inFile%.*}.err";
		if [[ $? != 0 ]]; then
        		echo "NIEPOPRAWNE WYJŚCIE STDERR DLA WEJŚCIA $inFile"
    		fi
	fi
done

rm "temp.err"
