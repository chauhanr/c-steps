echo "Running unit tests" 

for i in tests/*_tests
do 
	if tests -f $i
	then 
		if $VALGRIND ./$i 2>> tests/tests.log
		then 
			echo $i PASS 
		else 
			echo "Error in test $i: here is the tests/tests.log" 
			echo "---------"
			exit 1
		fi
	fi
done 

echo "Ending the tests cycle"
