# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlaranje <tlaranje@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/23 11:56:10 by tlaranje          #+#    #+#              #
#    Updated: 2025/10/28 15:48:58 by tlaranje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_put_char_str.c ft_put_ptr_hex.c ft_put_nbr_unbr.c
BONUS = ft_put_bonus.c
OBJS = $(SRC:.c=.o)
BONUS_OBJS = ${BONUS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)

bonus:
	@make OBJS="$(OBJS) $(BONUS_OBJS)" all --no-print-directory

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
