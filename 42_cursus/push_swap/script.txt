
for i in [1..50]
do
	ARG=`generator 500 0 500` && ./push_swap $ARG | ../checker_linux $ARG
done
