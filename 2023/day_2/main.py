import re

def main() -> None:
	RED_TOTAL_CUBES = 12
	GREEN_TOTAL_CUBES = 13
	BLUE_TOTAL_CUBES = 14

	possible_games = []

	game_ID = 0
	games = []

	with open('Inputs/2_input.txt') as file:
		for line in file:
			is_possible = False

			game_ID, games = splitGameString(line)

			for game in games:
				is_possible = isPossible(game, RED_TOTAL_CUBES, GREEN_TOTAL_CUBES, BLUE_TOTAL_CUBES)

				print('Game {}: {} is {}'
					  .format(game_ID, 
					  		  game, 
					  		  ('posible' if is_possible else 'imposible')))


def splitGameString(gameString) -> str:
	game_ID = 0
	games = []

	game_ID = re.findall('\d+(?=:)', gameString)[0]
	games = re.findall('(?<=: ).*', gameString)[0].split('; ')

	return game_ID, games


def isPossible(game, red_cubes, green_cubes, blue_cubes) -> bool:
	return True


if __name__ == '__main__':
	main()