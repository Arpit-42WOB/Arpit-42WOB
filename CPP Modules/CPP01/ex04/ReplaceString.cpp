/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceString.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:16:40 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/28 16:13:05 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceString.hpp"

ReplaceString::ReplaceString()
{
}

ReplaceString::ReplaceString(std::string fileName)
{
	this->openFile(fileName);
}

ReplaceString::~ReplaceString()
{
	this->_fileStreamIn.close();
}

void	ReplaceString::closeFile()
{
	this->_fileStreamIn.close();
}

void	ReplaceString::openFile(std::string fileName)
{
	if (this->_fileStreamIn.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return ;
	}
	this->_fileStreamIn.open(fileName.c_str());
	if (this->_fileStreamIn.fail())
	{
		std::cout << "Error opening file" << std::endl;
		return ;
	}
	this->_fileName = fileName;
}

void	ReplaceString::replaceString(std::string outFileName, std::string oldWord, std::string newWord)
{
	if (!this->_fileStreamIn.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return ;
	}
	std::ofstream	outFileStream;
	outFileStream.open(std::string(outFileName + ".replace").c_str());
	if (outFileStream.fail())
	{
		std::cout << "Error opening file" << std::endl;
		return ;
	}
	std::stringstream strStream;
	std::string text, substr;
	std::size_t start = 0;
	std::size_t newPos = 0;
	
	strStream << this->_fileStreamIn.rdbuf();
	text = strStream.str();
	strStream.str("");
	while (1)
	{
		newPos = text.find(oldWord, start);
		if (newPos == std::string::npos)
			break ;
		outFileStream << text.substr(start, newPos - start);
		outFileStream << newWord;
		start = newPos + oldWord.length();
	}
	outFileStream << text.substr(start, text.length() - start);
	outFileStream.close();
}
