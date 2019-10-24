NAME_ps= Make_ps
NAME_checker=Make_checker

all:
	$(MAKE) -f $(NAME_ps)
	$(MAKE) -f $(NAME_checker)

clean:
	$(MAKE) -f $(NAME_ps) clean
	$(MAKE) -f $(NAME_checker) clean

fclean: clean
	$(MAKE) -f $(NAME_ps) fclean
	$(MAKE) -f $(NAME_checker) fclean

re: fclean all
