# include <iostream>
# include <vector>
using namespace std;

int main()
{
	int size;
	cin >> size;
	vector<int> arr(size); 

	for (int i=0 ; i<size ; i++)
	{
		cin >> arr[i];
	}
	
	int max_zeros = 0;
    for (int i = 0; i < size; i++) 
	{
        if (arr[i] != 0) //遇到第一個非零項
		{
            for (int j = i + 1; j < size; j++) //遇到第一個非零項後，繼續往後找
			{
                if (arr[j] != 0 && arr[j] != arr[i]) // 找到相異非零項
				{ 
                    int zeros = 0;
                    for (int k = i + 1; k < j; k++) 
					{
                        zeros++; //計算中間有幾個0
                    }
                    max_zeros = max(max_zeros, zeros); // 將相異非0項之間0的個數做存取，且存取結束後會與先前存的值做比較
                    i = j - 1; // 跳過已經處理的範圍
                    break;
                } 
				else if (arr[j] != 0 && arr[j] == arr[i]) // 遇到相同非零項
				{ 
					i = j - 1;//直接跳過
      		        break;
    		   	}
            }
        }
    }

    cout << max_zeros << endl;
	
	

	return 0;
}