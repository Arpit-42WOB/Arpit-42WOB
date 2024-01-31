/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceString.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:16:43 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/26 20:12:03 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACESTRING_HPP
#define REPLACESTRING_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cerrno>

class ReplaceString
{
private:
	std::string _fileName;
	std::ifstream _fileStreamIn;
public:
	ReplaceString();
	ReplaceString(std::string fileName);
	~ReplaceString();
	
	void replaceString(std::string outFileName, std::string oldWord, std::string newWord);
	void openFile(std::string fileName);
	void closeFile();
};

#endif
