package com.example.todolist;


import androidx.lifecycle.LiveData;
import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;

import androidx.room.Query;
import androidx.room.Update;

import java.util.List;


@Dao
public interface NoteDao {
@Query("select * from Notes")
public LiveData<List<Note>> getAllData();




}




