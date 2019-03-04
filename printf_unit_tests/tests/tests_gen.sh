#!/bin/sh

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
NC='\033[0m'

# Parameters
TMPL_FOLDER_PATH=../templates
TMPL_LAUNCHER_FILE_NAME=000_launcher_template.c
TMPL_LAUNCHER=$TMPL_FOLDER_PATH/$TMPL_LAUNCHER_FILE_NAME
TMPL_TEST_FILE_NAME=XXX_test_template.c
TMPL_TEST=$TMPL_FOLDER_PATH/$TMPL_TEST_FILE_NAME
TMPL_HEADER_FILE_NAME=header_template.h
TMPL_HEADER=$TMPL_FOLDER_PATH/$TMPL_HEADER_FILE_NAME
TMPL_MAIN_FILE_NAME=main_template.h
TMPL_MAIN=$TMPL_FOLDER_PATH/$TMPL_MAIN_FILE_NAME
MAKEFILE_FILE=file_paths;
TESTS_FILE=tests.txt
BAK_FOLDER=backup

# Print error message
print_err(){
    printf "${RED}%s${NC}\n" "$1"
}

# Print message ok
print_ok(){
    printf "${GREEN}%s${NC}\n" "$1"
}

# Print warning message
print_warn(){
    printf "${YELLOW}%s${NC}\n" "$1"
}

folder_exists(){
	[ -d "$1" ] && return 1 || return 0
}

save_folder(){
	echo "Saving ${BLUE}$1${NC} folder in ${BLUE}$BAK_FOLDER${NC} folder..."
	cp -R $1 $BAK_FOLDER
	if [ $? -ne 0 ]; then
		print_err "Error: could not save $1 folder."
		return -1;
	fi
}

create_folder(){
	echo "Making ${BLUE}$1${NC} folder..."
	if [ ! -d $1 ]; then
		mkdir $1
		folder_exists $1
		if [ "$?" -eq 1 ]; then
			print_ok "$1 folder succesfully created" 
		else
			print_err "Error: could not create $1."
			return -1
		fi
	else
		print_warn "$1 folder already exists."
	fi
	return 0
}

remove_folder(){
	if [ -d $1 ]; then
		save_folder $1
		[ $? -ne 0 ] && return -1
		echo "Removing ${BLUE}$1${NC} folder..."
		rm -rf $1
		return 0;
	else
		echo "${BLUE}$1${NC} already removed."
		return -1
	fi
}

create_all_folders(){
	for fct in "$@"
	do
		create_folder $fct
	done
}

remove_all(){
	echo "Removing all folders..."
	create_folder $BAK_FOLDER
	[ "$?" -ne 0 ] && return -1
	for fct in "$@"
	do
		remove_folder $fct
	done
}

replace_fct_name(){
	local fct_name="$1"
	sed "s/TMPL_FCT_NAME/${fct_name}/" $fct_name/000_launcher.c > $fct_name/000_launcher_tmp.c
	rm -f $fct_name/000_launcher.c
	mv $fct_name/000_launcher_tmp.c $fct_name/000_launcher.c
}

replace_args(){
	local fct_name="$1"
	local args="$2"
	sed "s/TMPL_FCT_NAME/${args}/" $fct_name/000_launcher.c > $fct_name/000_launcher_tmp.c
	rm -f $fct_name/000_launcher.c
	mv $fct_name/000_launcher_tmp.c $fct_name/000_launcher.c
}

load_test(){
	local fct_name="$1"
	local test_fct="$2"
	local test_name=`echo "$3" | sed 's/"/\\\\\\\"/g'`
	sed "s/\/\*LOAD_TEST_HERE\*\//if ((err = load_test(\&test_list, \"${test_name}\","$'\\\n\\\t\\\t\\\t'"\&${fct_name}_${test_fct}, SUCCESS)))"$'\\\n\\\t\\\t'"return (err);"$'\\\n\\\t'"&/" \
		$fct_name/000_launcher.c > $fct_name/000_launcher_tmp.c
	rm -f $fct_name/000_launcher.c
	mv $fct_name/000_launcher_tmp.c $fct_name/000_launcher.c
}

add_template_to_folder(){
	local fct_name=$1
	echo "Adding 000_launcher.c template to ${BLUE}$fct_name${NC} folder..."
	cp $TMPL_LAUNCHER $fct_name/000_launcher.c
}

create_test(){
	local fct_name="$1"
	local test_fct="$2"
	local args="$3"
	local index="$4"

	echo "Creating test file ${BLUE}${index}_${test_fct}.c${NC} in ${BLUE}${fct_name}${NC} folder..."
	cp ${TMPL_TEST} ${fct_name}/${index}_${test_fct}.c
	sed -e "s/TMPL_FCT_NAME/${fct_name}/" -e "s/TMPL_TEST_FCT_NAME/${test_fct}/" -e "s/TMPL_ARGS/${args}/" ${fct_name}/${index}_${test_fct}.c > ${fct_name}/${index}_${test_fct}_tmp.c
	rm -f ${fct_name}/${index}_${test_fct}.c
	mv ${fct_name}/${index}_${test_fct}_tmp.c ${fct_name}/${index}_${test_fct}.c
}

add_prototypes(){
	local fct_name="$1"
	local test_fct="$2"

	if [ ! -f ${fct_name}/${fct_name}.h ]; then
		echo "Adding ${BLUE}${fct_name}.h${NC} from template file..."
		cp ${TMPL_HEADER} ${fct_name}/${fct_name}.h
		sed "s/TMPL_FCT_NAME/${fct_name}/" ${fct_name}/${fct_name}.h > ${fct_name}/${fct_name}_tmp.h
		rm -rf ${fct_name}/${fct_name}.h
		mv ${fct_name}/${fct_name}_tmp.h ${fct_name}/${fct_name}.h
	fi
	echo "Adding prototype for ${BLUE}${test_fct}${NC} test in ${BLUE}${fct_name}.h${NC}..."
	sed "s/\/\*PROTOTYPES_HERE\*\//int"$'\\\t'"${fct_name}_${test_fct}(void);"$'\\\n'"&/" ${fct_name}/${fct_name}.h > ${fct_name}/${fct_name}_tmp.h
	rm -f ${fct_name}/${fct_name}.h
	mv ${fct_name}/${fct_name}_tmp.h ${fct_name}/${fct_name}.h
}

save_file_path(){
	local fct_name="$1"
	local file_name="$2"
	echo "Adding ${BLUE}${fct_name}/${file_name}${NC} to ${BLUE}${MAKEFILE_FILE}${NC}..."
	echo "${fct_name}/${file_name} \\" >> $MAKEFILE_FILE
}

add_fct_in_main(){
	local fct_name="$1"
	sed -e "s/\/\*FCTS_HERE\*\//{\"${fct_name}\", ${fct_name}_launcher},"$'\\\n\\\t'"&/" -e "s/\/\*PROTOTYPES_HERE\*\//int"$'\\\t'"${fct_name}_launcher(void);"$'\\\n'"&/" main.h > main_tmp.h
	rm -f main.h
	mv main_tmp.h main.h
}

generate_tests(){
	local fcts=`cat $TESTS_FILE | cut -d';' -f1 | sort | uniq`
	printf "" > ${MAKEFILE_FILE}
	cp ${TMPL_MAIN} ./main.h
	for fct in $fcts
	do
		create_folder $fct
		add_template_to_folder $fct
		replace_fct_name $fct
		save_file_path "$fct" "000_launcher"
		add_fct_in_main "$fct"
		tests=`grep -w $fct tests.txt | cut -d';' -f2`
		local index=1
		for test_fct in $tests
		do
			local index_pref=`printf %03d $index`
			test_name=`grep -w $fct tests.txt | grep -w $test_fct |  cut -d';' -f3`	
			create_test "$fct" "$test_fct" "$test_name" "$index_pref"
			add_prototypes "$fct" "$test_fct"
			load_test "$fct" "$test_fct" "$test_name"
			save_file_path "$fct" "${index_pref}_${test_fct}"
			((index++))
		done
	done
	sed -e "1s/^/SRC_NAME += /" -e "$ s/ \\\//" ${MAKEFILE_FILE} > ${MAKEFILE_FILE}_tmp
	rm -rf ${MAKEFILE_FILE}
	mv ${MAKEFILE_FILE}_tmp ${MAKEFILE_FILE}
}

clean_tests(){
	local fcts=`cat $TESTS_FILE | cut -d';' -f1 | sort | uniq`
	echo "Removing ${BLUE}$BAK_FOLDER${NC}..."
	rm -rf $BAK_FOLDER
	remove_all $fcts
}

launch_tests(){
	make test
}

if [ "$1" = "create" ]; then
	generate_tests
	launch_tests
fi

if [ "$1" = "clean" ]; then
	clean_tests
fi
