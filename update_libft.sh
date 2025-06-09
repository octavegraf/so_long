cd ../ft_printf
git submodule update --remote --merge libft
git add .
git commit -m 'updated libft'
git push
cd ../so_long
git submodule update --remote --merge ft_printf
git add ft_printf
git commit -m 'updated libft'
git push
echo "Libft has been updated in the current repository."