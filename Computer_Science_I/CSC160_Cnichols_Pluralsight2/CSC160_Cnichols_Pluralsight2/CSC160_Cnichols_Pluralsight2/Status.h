#pragma once

//Ill be honest i still do not really know how this works,
//im just copying the lady's format and hoping it works even somewhat
enum studentStatus
{
	Attending,
	NonAttending,
	Graduated,
};

enum class FileError
{
	notfound,
	ok
};

enum class NetworkError
{
	disconnected,
	ok
};
