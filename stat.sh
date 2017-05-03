# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stat.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfontain <tfontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 23:38:53 by tfontain          #+#    #+#              #
#    Updated: 2017/05/02 14:15:55 by lchety           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

player2=lchety.filler
player1=grati.filler

n_turns=20
map=01

# dont touch after this line --------------------------------------------------

p1=0;
p2=0;

while [ $n_turns != 0 ]
do
	./resources/filler_vm -f ./resources/maps/map$map -p1 \
		./resources/players/$player1 -p2 \
		./resources/players/$player2
	result=$(cat filler.trace | grep won)
	if echo "$result" | grep -q "$player1"
	then
		((p1++))
	else
		((p2++))
	fi
	((n_turns--))
done

echo $player1
echo $p1
echo $player2
echo $p2
