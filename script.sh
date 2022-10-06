git clone https://github.com/42Paris/minilibx-linux \
&& cd minilibx-linux \
&& sudo apt-get install libxext-dev libxrandr-dev libx11-dev libbsd-dev libssl-dev \
&& make \
&& sudo mv man/man1 /usr/local/man/ \
&& sudo mv libmlx.a /usr/local/lib/ \
&& sudo mv mlx.h /usr/local/include/ 