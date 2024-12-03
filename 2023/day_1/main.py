import re

def main() -> int:
	units = ["zero", "one", "two", "three", "four", 
         "five", "six", "seven", "eight", "nine"]

	with open('Inputs/1_input.txt') as file:

		result = 0
		position = 1

		for line in file.readlines():

			number = []
			start_number = 0
			end_number = 0

			number = re.sub("[a-zA-Z\n]", "", line)
			line_start = line[:line.find(number[0])]
			line_end = line[line.find(number[-1]) + 1:]

			start_number = number[0]
			end_number = number[-1]

			for unit in units:
				if unit in line_start:
					start_number = str(units.index(unit))
				if unit in line_end:
					end_number = str(units.index(unit))

			final_number = int(start_number + end_number)
			result += final_number
			print('{}. {}'.format(position, final_number))
			position += 1
			
	print(f'Total: {result}')

	return 0


if __name__ == __main__:
	main()