# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generator.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:45:29 by lzipp             #+#    #+#              #
#    Updated: 2023/12/01 11:13:15 by lzipp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
import string

def generate_mixed_chars(num_chars):
	safe_ascii_chars = string.ascii_letters + string.digits + "-_."
	unicode_chars = ''.join(chr(i) for i in range(0x0400, 0x0450))
	combined_chars = safe_ascii_chars + unicode_chars
	return ''.join(random.choice(combined_chars) for _ in range(num_chars))

def write_to_file(filename, content):
	with open(filename, 'w', encoding='utf-8') as file:
		file.write(content)

num_chars = 100
mixed_chars = generate_mixed_chars(num_chars)
write_to_file('test1.txt', mixed_chars)