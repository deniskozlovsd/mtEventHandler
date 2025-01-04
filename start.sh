#! /bin/bash

#menu
while true; do
printf "\nWhat to do :\n"
printf "|----------------------------------------------------------|\n"
choises=("build cmake" "launch" "clean")
select chs in "${choises[@]}"
 do 
  case $chs in
  "build cmake")
  printf "Building ...\n"
	cmake -GNinja .
	cmake --build .
  break
;;
  "launch")
  printf "launching app... \n"
  ./ehandler
  break
;;
  "clean")
  printf "Cleaning... \n"
  rm -rf CMakeFiles
  rm CMakeCache.txt
  break
;;

  *) echo "Invalid option $REPLY";;
  esac
done
read -p "Press [Enter] key to continue... "
done
