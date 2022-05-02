##
## EPITECH PROJECT, 2022
## B-FUN-400-MPL-4-1-wolfram-diogo.faria-martins
## File description:
## Makefile
##

local_path	:=	$(shell stack path --local-install-root)
executable	:=	$(local_path)/bin
NAME	=	wolfram

all:
	@stack build
	@stack path --local-install-root
	cp $(executable)/wolfram-exe ./$(NAME)

clean:
	@stack clean

fclean:
	@rm -f $(NAME)
	@rm -rf .stack-work

re: fclean all
