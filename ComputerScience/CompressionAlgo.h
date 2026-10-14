#pragma once

#include <string>
#include <vector>
namespace COmpressionAlgo
{
	std::vector<char> Huffman(std::string toCompress);
	void CompressFile(std::vector<char>& txt, std::string path);
}

