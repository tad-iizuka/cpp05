# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/02 02:23:47 by tiizuka           #+#    #+#              #
#    Updated: 2025/08/02 02:29:41 by tiizuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of target
NAME		=	ex00

# Source, object files
SRCS 		=	main.cpp Bureaucrat.cpp Log.cpp

OBJS		=	$(SRCS:.cpp=.o)

# Compiler setting
CXX			=	c++
CXXFLAGSS	=	-Wall -Wextra -Werror -pedantic -g -std=c++98

# Remove command
RM			= rm

all:		${NAME}

$(NAME) :	$(OBJS)
			$(CXX) $(CXXFLAGSS) -o $(NAME) $(OBJS)

%.o: %.cpp
			$(CXX) $(CXXFLAGSS) -c $< -o $@

# Rule for cleaning object files
clean:
ifneq		("$(wildcard $(OBJS))", "")
			rm $(OBJS)
endif

# Rule for full clean
fclean:		clean
ifneq		("$(wildcard $(NAME))", "")
			rm -f $(NAME)
endif

# Rule for re-build
re:			fclean all

# Phony targets
.PHONY:		all clean fclean re
