#include "DataSorter.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text::RegularExpressions;
using namespace System::Diagnostics;

DataSorter::DataSorter (List<String^>^ dataList, List<String^>^ templatesList) {
	this->dataList = dataList;
	this->templatesList = templatesList;
	lastResults = gcnew Dictionary<Regex^, List<String^>^>();
}

DataSorter::~DataSorter() {
	delete dataList;
	delete templatesList;
}

List<String^>^ DataSorter::getDataList() {
	return this->dataList;
}

void DataSorter::setDataList(List<String^>^ data) {
	dataList = data;
}

List<String^>^ DataSorter::getTemplatesList() {
	return this->templatesList;
}

void DataSorter::setTemplatesList(List<String^>^ templates) {
	templatesList = templates;
}

Dictionary<Regex^, List<String^>^>^ DataSorter::execute() {
	Stopwatch^ stopwatch = gcnew Stopwatch();
	stopwatch->Start();

	this->lastResults->Clear();

	for each (String ^ regexStr in this->templatesList) {
		Regex^ regex = gcnew Regex(regexStr);
		//List<String^>^
		//this->lastResults->Add(regex, this->getDataMatchingRegex(regex));
	}

	stopwatch->Stop();
	this->executionTime = stopwatch->ElapsedMilliseconds;
	return getLastResult();
}

Dictionary<Regex^, List<String^>^>^ DataSorter::getLastResult() {
	return this->lastResults;
}

List<String^>^ DataSorter::getDataMatchingRegex(Regex^ regex) {
	List<String^>^ resultList = gcnew List<String^>();
	for each (String ^ str in this->dataList) {
		MatchCollection^ matches = regex->Matches(str);
		for each (Match ^ match in matches) {
			if(String::Compare(match->Value, str) == 0) resultList->Add(str);
		}
	}
	return resultList;
}

long long DataSorter::getExecutionTime() {
	return this->executionTime;
};
