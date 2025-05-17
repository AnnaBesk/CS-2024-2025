cmake_minimum_required(VERSION 3.10)

set(animals "cat;mouse;dog;elephant;tiger;lion;axolotl;hippo;squirrel;wolf;shark;whale;bee;sloth;sheep;giraffe;scorpion")

message("${animals}")

#вывести всех с новой строчки
foreach(ITEM IN LISTS animals)
  message("${ITEM}")
endforeach()

#найти длину 
list(LENGTH animals l)
message("${l}")

#печатать только те, у которых больше 4 букв
foreach(ITEM IN LISTS animals)
    string(LENGTH ${ITEM} len)
    if(len GREATER 4)
        message("${ITEM}")
    endif()
endforeach()

message("    ")

#животные только на букву S
foreach(ITEM IN LISTS animals)
    string(SUBSTRING "${ITEM}" 0 1 first_char)
    if(first_char STREQUAL "s")
        message("${ITEM}")
    endif()
endforeach()

message("    ")
#сортировка
list(SORT animals)
foreach(ITEM IN LISTS animals)
    message("${ITEM}")
endforeach()

#печатать в одну строку
string(REPLACE ";" " " animals_line "${animals}")
message("${animals_line}")

#запись в Файл
file(WRITE data.txt "${animals_line}\n")
message("Файл data.txt создан")

#создание файлов
file(MAKE_DIRECTORY animal_files)
foreach(ITEM IN LISTS animals)
    file(WRITE "animal_files/${ITEM}.txt" "This is ${ITEM}\n")
endforeach()


