#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);

  int floors;
  int *floorsizes, **items;
  string ***trojans;
  string curr;

  input >> floors;
  trojans = new string**[floors];
  //you will need to keep track of how many people are on each floor.
  floorsizes = new int[floors];
  items = new int *[floors];

  for (int i = 0; i < floors; i++) {
	  floorsizes[i] = 0;
	  trojans[i] = NULL;
	  items[i] = NULL;
  }

  while(getline(input, curr))
    {
	  stringstream ss;
	  ss << curr;
	  ss >> curr;
	  if (curr == "MOVEIN") {
		  int i,k;
		  ss >> i;
		  ss >> k;
		  if (ss.fail()) {
			  output << "Error - Incorrect command" << endl;
			  continue;
		  }
		  else
            {
                if (i >= floors)
                {
                    output << "Error - Floor " << i << " does not exist" << endl;
                    continue;
                }
                else if (floorsizes[i] != 0)
                {
                    output << "Error - Floor " << i << " is not empty" << endl;
                    continue;
                }
                trojans[i] = new string* [k];
                floorsizes[i] = k;
                items[i] = new int [(floorsizes[i])];
                // Set each student ID's pointer to NULL to indicate no possessions
                for(int x = 0; x < k; x++)
                {
                    items[i][x] = 0;
                    trojans[i][x] = NULL;
                }
		  }
	  }
	  else if (curr == "MOVEOUT") {
	      int i;
	      ss >> i;
	      if (ss.fail())
            {
			  output << "Error - Incorrect command" << endl;
			  continue;
            }
		  else
            {
                if (i >= floors)
                {
		          output << "Error - Floor " << i << " does not exist" << endl;
		          continue;
                }
                else if (floorsizes[i] == 0)
                {
                    output << "Error - Floor " << i << " is empty" << endl;
                    continue;
                }
                else
                {
                    for(int x = 0; x < floorsizes[i]; x++)
                    {
                        if (trojans[i][x] != NULL)
                        {
                            delete trojans [i][x];
                        }

                    }
                    delete trojans[i];
                    trojans[i] = NULL;
                    items[i] = NULL;
                    floorsizes[i] = 0;
                }
            }
	  }

	  else if (curr == "OBTAIN")
        {
	      int i, j, k;
	      string poss;
	      ss >> i;
	      ss >> j;
	      ss >> k;
	      getline(ss, poss);
	      if (ss.fail()) {
			  output << "Error - Incorrect Command" << endl;
			  continue;
		  }
		  else if (i >= floors)
          {
              output << "Error - Floor " << i << " does not exist" << endl;
              continue;
          }
		  else if (j >= floorsizes[i])
		  {
		      output << "Error - Student " << j << " does not exist on Floor " << i << endl;
		      continue;
		  }
		  else if (trojans[i][j] != NULL)
          {
              output << "Error - Student " << i << " already has possessions" << endl;
              continue;
          }

          else
		  trojans[i][j]= new string [k];
		  trojans[i][j][0] = poss;
		  items[i][j] = k;
	  }
	  else if (curr == "OUTPUT") {
            int i, j;
            ss >> i;
            ss >> j;
            if (ss.fail()) {
			  output << "Error - Incorrect command" << endl;
			  continue;
            }
            if(i >=floors)
            {
                output << "Error - Floor " << i <<" does not exist" << endl;
                continue;
            }
            else if(j >=(floorsizes[i]))
            {
                output << "Error - Student " << j << " does not exist on Floor " << j << endl;
                continue;
            }
            else if(trojans[i][j] == NULL || items[i][j] == 0)
            {
                output << "Error - Student " << j << " has no possessions" << endl;
                continue;
            }
            else
            {
                stringstream oss (trojans[i][j][0]);
                string sout;
                for(int x = 0; x < items[i][j]; x++)
                {
                    oss >> sout;
                    output << sout << endl;
                }

            }
	  }

	  //Improper Command Entry/Usage Error
	  else if (curr != "")
        {
            output << "Error - Invalid Command. Valid Commands: MOVEIN(i,j), MOVEOUT(i), OBTAIN(i,j,k, n1, n2...nk), OUTPUT(i,j)" << endl;
            continue;

        }
    }

  //Delete everything
  for(int x = 0; x < floors; x++)
  {
      for(int y = 0; y < floorsizes[x]; y++)
      {
          delete trojans[x][y];

      }
      delete trojans[x];
      trojans[x] = NULL;
      delete items[x];
      items[x] = NULL;
  }
  delete [] items;
  delete [] trojans;


  return 0;
}

