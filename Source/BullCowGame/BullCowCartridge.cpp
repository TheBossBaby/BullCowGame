// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        InitGame();
    }
    else
    {
        CheckInput(Input);
    }
}

void UBullCowCartridge::CheckInput(const FString& Input)
{
    if (HiddenWord.Equals(Input))
    {
        PrintLine(TEXT("You Won"));
        EndGame();
    }
    else
    {
        --Lives;
        PrintLine(TEXT("You have lost a life!!"));
        if (Lives > 0)
        {
            if (HiddenWord.Len() != Input.Len())
            {
                PrintLine(TEXT("Hidden Word is of, %i characters\nPlease try again!"), HiddenWord.Len());
            }
        }
        else
        {
            EndGame();
        }
    }
}

void UBullCowCartridge::InitGame()
{
    PrintLine(TEXT("Welcome to Bull Cow"));
    HiddenWord = TEXT("ishan");
    Lives = HiddenWord.Len();
    bGameOver = false;
    PrintLine(TEXT("Guess %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Please type something, and press enter"));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("You lost\npress Enter to Continue!"));
}