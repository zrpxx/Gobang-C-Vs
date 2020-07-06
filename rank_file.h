#pragma once
#ifndef _RANK_FILE_H_
#define _RANK_FILE_

struct Rank* createList();
struct Rank* createNode();
struct Rank* sortRank(struct Rank*);
void insertRank(struct Rank*, int);

#endif